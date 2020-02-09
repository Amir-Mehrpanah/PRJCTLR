len = 1001
M = zeros(len,len);
shift = ceil(len/2);
M(shift,shift) = 1;
point = [0,0];
FC = 0;
F = [0,-1];
R = [0 -1;1 0];
c=2;
while FC < len
    for rep = [1,2]
        for i = [1:FC]
            point+=F;
            M(point(1)+shift,point(2)+shift) = c++;
        end
        F = F*R;
    end
    FC++;
end
for i = [1:FC-1]
    point+=F;
    M(point(1)+shift,point(2)+shift) = c++;
end
sum(M(len:len-1:end-1))+trace(M)-1
