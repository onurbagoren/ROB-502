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

DICTIONARY_DIR=/usr/share/dict/words
letters=(a b c d e f g h i j k l m n o p q r s t u v w x y z)
max_value=-1
accompanying_letter=""
for var in ${letters[@]}; do
    filename="$var".txt
    grep "^[$var]" $DICTIONARY_DIR > ./$filename
    
    num_words=$( cat ./$filename | wc -l )
    if [ $num_words -gt $max_value ] ; then
        max_value=$num_words
        accompanying_letter=$var
    fi
done

echo "The letter $accompanying_letter begins with the largest number of words: $max_value"
head -n 20 ./$accompanying_letter.txt
