module UNSIGNED_MULT_tb(); parameter width=4 ; 
  reg  [width-1:0] A_tb;
  reg  [width-1:0] B_tb;
  wire  [2*width-1:0] C_tb;






UNSIGNED_MULT DUT(

.A(A_tb),
.B(B_tb),
.C(C_tb));




 parameter clock_period=10; 
 






 initial 
 begin 

A_tb='b0;
B_tb='b0;
 #(clock_period) 
A_tb='d3;
B_tb='d4;
 #(clock_period)
 A_tb='d5;
B_tb='d5;
 #(clock_period)
 A_tb='d2;
B_tb='d1;



 end 
 endmodule