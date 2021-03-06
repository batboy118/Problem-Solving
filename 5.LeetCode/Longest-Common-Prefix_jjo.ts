function longestCommonPrefix(strs: string[]): string {
    if(strs.length ==0 ) return '';
    let prefix = strs[0];
    for(let i = 1; i < strs.length; i++){
        let j = 0;
        while(j < prefix.length && prefix[j] == strs[i][j]){
            j++;
        }
        prefix = prefix.substring(0, j);
        if(prefix == '') break;
    }
    return prefix;
};
