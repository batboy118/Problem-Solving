function isAnagram(s: string, t: string): boolean {
    let m = new Map();
    for(let c of s){
        m.set(c, ((m.get(c)|0) + 1));
    }
    for(let c of t){
        if(!m.get(c)) return false;
        m.set(c, m.get(c) - 1);
    }
    for(let item of m){
        if(item[1] != 0) return false;
    }
    return true;
};
