t=linspace(-20,18,10001);
y= exp(-4*t).*heaviside(t);
h=2.*heaviside(t);
g=2*exp(-t).*heaviside(t);
f=conv(y,(h+g),'same')*(20/10000);
subplot(211);
plot(t,f)
subplot(212);
co=(((2/3)*(exp(-t)-exp(-4*t)))+((1/2)*(1-exp(-4*t)))).*(heaviside(t)-heaviside(t-50));
plot(t,co);

