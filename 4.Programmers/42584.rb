# Programmers
# no. 42584
# 주식가격
# https://programmers.co.kr/learn/courses/30/lessons/42584
# by JH (batboy118)

#제출 코드 (without main)
def solution(prices)
    answer = []
    s = []
    prices.length.times {|i|
        while s.length > 0 && prices[s.last] > prices[i]
            answer[s.last] = i - s.last;
            s.pop();
        end
        s.push(i);
    }
    while s.length > 0
            answer[s.last] = prices.length - 1 - s.last;
            s.pop();
    end
    return answer
end
