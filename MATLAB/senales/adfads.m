t=linspace(-18,18,10001);
y= exp(-4*t).*heaviside(t);
a=(2*exp(-t)+2).*heaviside(t);
subplot(211);
plot(t,y)
subplot(212);
plot(t,a);