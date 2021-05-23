#!/bin/bash

####
# Write a script letters.sh to divide the dictionary file at /usr/share/dict/words such that a new
# file a.txt contains only words that start with lowercase 'a', b.txt contains only words that
# start with lower case 'b', and so on all the way to z.txt. Output the letter that has the most
# words in the file along with that number number of words. Also output the top 20 words from that
# file. Use the exact parsin given here:
# The letter '*' begins with the largest number of words: ####
# WORD
# WORD
# WORD
# ...
# WORD
####

# Define variables
DICTIONARY_DIR=/usr/share/dict/words
LETTERS=(a b c d e f g h i j k l m n o p q r s t u v w x y z)
MAX_VALUE=-1
ACCOMPANYING_LETTER=""

# Iterate through the lowercase letters
# Can this be done using ASCII addresses instead?
for var in ${LETTERS[@]}; do
    # define file name
    FILENAME="$var".txt
    grep "^[$var]" $DICTIONARY_DIR > ./$FILENAME
   
    # check if the current file has more words than previous files
    NUM_WORDS=$( cat ./$filename | wc -l )
    if [ $NUM_WORDS -gt $MAX_VALUE ] ; then
        MAX_VALUE=$NUM_WORDS
        ACCOMPANYING_LETTER=$var
    fi
done

# Output for the in class assignment
echo "The letter $ACCOMPANYING_LETTER begins with the largest number of words: $MAX_VALUE"
head -n 20 ./$ACCOMPANYING_LETTER.txt
