function d=calcul_c(x1,y1,x2,y2);
d=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
endfunction

function r=calcul_angle(a,b,c);
r=acos((a*a + b*b - c*c)/(2 * a * b));
endfunction

function r=cot(a);
if (a > 1.56) & (a < 1.58) then
   r = 0;
else	
   r = 1 / tan(a);
end
endfunction

function triangulation(x1,y1,x2,y2,x3,y3,x0,y0);
xq1 = x1 - x2
yq1 = y1 - y2
xq3 = x3 - x2
yq3 = y3 - y2

disp ("xq1 = " + string(xq1) + ", yq1 = " + string(yq1) )
disp ("xq3 = " + string(xq3) + ", yq3 = " + string(yq3) )

distT1 = calcul_c (x1,y1,x0,y0)
distT2 = calcul_c (x2,y2,x0,y0)
distT3 = calcul_c (x3,y3,x0,y0)

disp ("distt1 =" + string(distT1) + " distt2 =" + string(distT2) + " distt3 =" + string(distT3))

c1 = calcul_c (x1,y1,x2,y2)
c2 = calcul_c (x2,y2,x3,y3)
c3 = calcul_c (x3,y3,x1,y1)

disp ("c1 = " + string(c1) + " c2 =" + string(c2) + " c3 =" + string(c3))

a12 = calcul_angle (distT1,distT2,c1)
a23 = calcul_angle (distT2,distT3,c2)
a31 = calcul_angle (distT3,distT1,c3)

disp ("a12 = " + string(a12) + " a23 = " + string(a23) + " a31 = " + string(a31))

T12 = cot(a12)
T23 = cot(a23)
T31 = cot(a31)


disp ("T12 = " + string(T12) + " T23 = " + string(T23) + " T31 = " + string(T31))

xq12 = xq1 + (T12 * yq1)
yq12 = yq1 - (T12 * xq1)

disp ("xq12 = " + string(xq12) + ", yq12 = " + string(yq12) )

xq23 = xq3 - (T23 * yq3)
yq23 = yq3 + (T23 * xq3)

disp ("xq23 = " + string(xq23) + ", yq23 = " + string(yq23) )

xq31 = (xq3 + xq1) + (T31 * (yq3 - yq1))
yq31 = (yq3 + yq1) - (T31 * (xq3 - xq1))

disp ("xq31 = " + string(xq31) + ", yq31 = " + string(yq31) )

kq31 = (xq1 * xq3) + (yq1 * yq3) + (T31 * (xq1*yq3 - xq3*yq1))

disp ("kq31 = " + string(kq31))

D = (xq12 - xq23)*(yq23 - yq31) - (yq12 - yq23)*(xq23 - xq31)

disp ("D = " + string(D))

if D == 0 then disp("Err D = 0")
end
xr = x2 + ((kq31 * (yq12 - yq23)) / D )
yr = y2 + ((kq31 * (xq23 - xq12)) / D )

disp ("xcalcl = " + string(xr) + " ycalc = " + string(yr) + " \n")

endfunction