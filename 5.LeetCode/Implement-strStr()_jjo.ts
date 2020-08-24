function strStr(haystack: string, needle: string): number {
  for(let i = 0; i < haystack.length - needle.length + 1; i++){
    let j = 0;
    while(j < needle.length && haystack[i + j] == needle[j]){
      j++;
    }
    if(j == needle.length) return i;
  }
  return -1;
}
