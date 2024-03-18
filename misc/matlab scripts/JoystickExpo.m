defx = 0:100
x = defx-50

t=500;

val = exp(((abs(x)-50)*t)/1000) .* x;

figure
plot(defx, val+50)
hold on

legend
xlim([-50,150])
ylim([-50,150])
grid