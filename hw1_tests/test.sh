#!/bin/bash

BASEDIR=`pwd`
TESTDIR="$BASEDIR"
RESULTDIR="$BASEDIR"
TIMEOUT=10
LIMIT=100K
MAX=10
GCC=g++
SHELL="/bin/sh -c"

function log()
{
    echo "$@" >&2
}

function write_status()
{
    log "$1"
}


function run_tests()
{
    TMPDIR="$BASEDIR"
 
    CPPOPTS=

    for ID in `seq 1 $MAX`
    do
	log "Testing program $ID"
	SRC="$TMPDIR/prog$ID.cpp"
	EXE="$TMPDIR/prog$ID"
	if [ -f "$SRC" ]
	then
	    # try to compile
	    g++ -o "$EXE" $CPPOPTS "$SRC" 2>/dev/null
	    if [ -x "$EXE" ]
	    then
		# start tests for this program one by one
		for TESTIN in "$TESTDIR/$ID"?.test
		do
		    TESTBASE=`basename "$TESTIN" .test`
		    TESTOUT="$TESTIN".ans
		    PROGRESULT="$RESULTDIR"/"$TESTBASE"
		    PROGOUT="$PROGRESULT".out
		    PROGERR="$PROGRESULT".err

		    log -n "Running test $TESTBASE: "

		    # cleanup first
		    rm -f "$PROGOUT" "$PROGERR"

		    # run in a subshell, timeboxed and with limited output
		    STATUS=`timeout $TIMEOUT "$EXE" < "$TESTIN" 2> "$PROGERR" | head -c $LIMIT > "$PROGOUT"; echo ${PIPESTATUS[0]}`

		    # check for timeout
		    if [ $STATUS = 124 ]
		    then
			write_status "TO"
		    # check for output limit
		    elif [ $STATUS = 141 ]
		    then
			write_status "OL"
		    # check for runtime error
		    elif [ $STATUS != 0 ]
		    then
			write_status "RE"
		    else
			# check against expected output
			if diff -w "$PROGOUT" "$TESTOUT" > /dev/null 2> /dev/null
			then
			    write_status "OK"
			else
			    write_status "WA"
			fi
		    fi
		done
	    else
		for TESTIN in "$TESTDIR/$ID"?.test
		do
		    write_status "CE"
		done
	    fi
	else
	    for TESTIN in "$TESTDIR/$ID"?.test
	    do
		write_status "NA"
	    done
	fi
    done
    
}

run_tests
