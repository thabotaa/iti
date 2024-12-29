module shift_add3_tb(); parameter width=4 ; 
  reg  [7:0] binary_tb;
  wire  [11:0] BCD_tb;






Shift_Add3 DUT(

.binary(binary_tb),
.bcd(BCD_tb));




 parameter clock_period=10; 
 






 initial 
 begin 
binary_tb='b0;
 #(clock_period) 
 binary_tb='h4;
 #(clock_period)
 binary_tb='hc;
 #(clock_period)
 binary_tb='hc5;
 #(clock_period)
 binary_tb='hcc;
 #(clock_period)
 binary_tb='hff;



 end 
 endmodule

