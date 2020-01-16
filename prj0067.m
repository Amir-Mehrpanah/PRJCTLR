big = 100
t = zeros(big);
c = 1;
for i = 2:big + 1
    temp  = textread('content/d0067.txt','%d',c);
    for j = 1:i-1
        t(i-1,j) = temp(j + c - i + 1);
    end
    c += i;
end

for i = 2:big
    t(i,1) += t(i-1,1);
    t(i,i) += t(i-1,i-1);
end

for i = 3:big
    for j = 2:i-1
        t(i,j) += max(t(i-1,j-1),t(i-1,j));
    end
end

max(t(end,:))
