clc
clear
n=input('������� ������ �������: ');
w=1.5;
eps=10^-6;
for i=1:n
    for j=1:n
        A(i,j)=input ([sprintf('������� ������� ������� A(%d',i) sprintf(';%d',j) '): ']);
    end
end
for i=1:n
    f(i)=input ([sprintf('������� ������� ������� f%d',i) ': ']);
end
d = eig(A);
for i= 1:n   
    if d(i) < 0
        disp('������� �� ������������ ����������. ������� ������ �������.')
        return
    end  
end
A
f
D = diag(diag(A));
A1 = tril(A-D);
A2 = triu(A-D);

X = zeros(n,1);
i = 0;
toch = 1;
while toch > eps
    X1 = (inv(A1 + 1/w*D))*(f' -(A2 + (w-1)/w*D)*X);
    toch = abs(X1-X);
    X = X1;
    i = i + 1;
end
disp(sprintf('���������� ��������: %d',i))
disp('������� ����:') 
for i=1:n
    disp(sprintf(' %f',X(i)))
end

