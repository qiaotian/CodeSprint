////* 1st solution
I should count the words. So I chose the awk command.
I use a dictionary in awk. For every line I count every word in the dictionary.
After deal with all lines. At the END, use for (item in Dict) { #do someting# } to print every words and its frequency.
Now the printed words are unsorted. Then I use a | pipes and sort it by sort
* sort -n means "compare according to string numerical value".
* sort -r means "reverse the result of comparisons".
* sort -k 2 means "sort by the second word"
*////

gawk '\
{
    for (i=1; i<=NF; i++) { ++D[$i]; }
}
END {
    for (i in D) { print i, D[i] }
}' words.txt | sort -nr -k 2

////* 2nd solution
tr -s: truncate the string with target string, but only remaining one instance (e.g. multiple whitespaces)
sort: To make the same string successive so that uniq could count the same string fully and correctly.
uniq -c: uniq is used to filter out the repeated lines which are successive, -c means counting
sort -r: -r means sorting in descending order
awk '{ print $2, $1 }': To format the output
*////

cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'
