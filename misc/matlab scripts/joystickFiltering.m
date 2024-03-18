%% typul
mp1 = [0.1,0.3,0.5,0.7,0.9];

ns = 46;
bs = 98;

%c = (1-mp1)*b + n*mp1
%% dup
time = 1:1:50; % 1ms per iter
cx = 1:1:50

for z = 1:5
  cx = 1:1:50
  n = ns;
  b = bs;
  for i = 1:50
    c = (1-mp1(z))*b + n*mp1(z)
    b = c;
    cx(i) = c;
  end  
plot(time,cx)
hold on 
legend(num2str(mp1(1)),num2str(mp1(2)),num2str(mp1(3)),num2str(mp1(4)),num2str(mp1(5)))
end

 
