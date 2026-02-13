syms x t X omega;
x=21/(t^2+28);
X=simplify (int(x*exp(-j*omega*t),t,0,inf))