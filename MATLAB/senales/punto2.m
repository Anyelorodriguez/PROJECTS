t=linspace(-8,8,10001);
t1 = (-(t+2).^2).*(heaviside(t+4)-heaviside(t-2));
t2 = (-(t-2).^2).*(heaviside(t)-heaviside(t-6));
t3 = ((t).^2).*(heaviside(t+4)-heaviside(t-2));
t4 = 0.*(heaviside(t+4)-heaviside(t-2));
t5 = (-(t).^2).*(heaviside(t+2)-heaviside(t-4));
t6 = (-(2*t).^2).*(heaviside(t+1)-heaviside(t-2));
t7 = ((0.5*t).^2).*(heaviside(t+8)-heaviside(t-4));

subplot(421);
plot(t,t1)
subplot(422);
plot(t,t2);
subplot(423);
plot(t,t3);
subplot(424);
plot(t,t4);
subplot(425);
plot(t,t5);
subplot(426);
plot(t,t6);
subplot(427);
plot(t,t7);
