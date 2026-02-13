syms y(t)
eqn=diff(y,y,2)==-2*diff(y,t)-1*y+cos(3*t);
Dy=diff(y,t);
cond=[y(0)==0,Dy(0)==0];
ys(t)=dsolve(eqn,cond);
ys
fplot(t, ys ,[0 10])

