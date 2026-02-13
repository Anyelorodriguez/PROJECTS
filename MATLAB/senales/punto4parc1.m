t=linspace(-18,18,10001);
y= exp(-4*t);
h=2;
g=2*exp(-t);
f=conv(y,(h+g),'same')*(20/10000);
hold on;
grid on;
plot(t,f)