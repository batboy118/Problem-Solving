function firstUniqChar(s: string): number {
    let m = new Map();
    for(let i = 0; i <s.length; i++){
        if(m.has(s[i]))
            m.set(String(s[i]), m.get(s[i]) + 1);
        else
            m.set(String(s[i]), 1);
    }
    for(let i = 0; i <s.length; i++){
        if(m.get(String(s[i])) == 1) return i;
    }
    return -1;
};
