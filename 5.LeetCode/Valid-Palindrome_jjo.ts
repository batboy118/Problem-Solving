function isPalindrome(s: string): boolean {
    let str = s.toLowerCase().replace(/[^a-z0-9]/g,'');
    if(str.split("").reverse().join("") == str) return true;
    return false;
};
