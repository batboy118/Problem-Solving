/**
 Do not return anything, modify s in-place instead.
 */
function reverseString(s: string[]): void {
    for(let i = 0; i < s.length / 2; i++) [s[i], s[s.length - i - 1]] = [s[s.length - i - 1], s[i]];
};
