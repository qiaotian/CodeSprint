gawk '
{
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}' file.txt


#gawk和“'”之间必须有空格
gawk '
BEGIN{
    FS="\n";
    RS="";
    ORS=""
}
{
    lines[1]="";
    for(i=1;i<=NF;i++) {
        count=split($i,var," ");
        for(j=1;j<=count;j++) {
            lines[j]=lines[j]" "var[j];
        }
    }
    for(v in lines) {
        print substr(lines[v],2)"\n";
    }
}' file.txt
