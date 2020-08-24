function myAtoi(str: string): number {
  let sign = 1;
  let i = 0;
  while(str[i] == ' ') i++;
  if(str[i] == '-'){
      sign = -1;
      i++;
  } else if(str[i] == '+'){
      i++;
  }
  let n = 0;
  for(i; i < str.length && str[i] >= '0' && str[i] <= '9'; i++){
      n = (n * 10) + Number(str[i]);
  }
  n = n * sign;
  if(n > Math.pow(2, 31) - 1) return Math.pow(2, 31) - 1;
  else if (n < -Math.pow(2, 31)) return -Math.pow(2, 31);
  return n;
};
