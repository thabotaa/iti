module top_module_tb(); parameter width=4;
 reg [width-1:0] A_tb;
 reg [width-1:0] B_tb;
 wire [6:0] out1_tb;
 wire [6:0] out2_tb;
 wire [6:0] out3_tb;
 
 top_module DUT(
 .A(A_tb),
 .B(B_tb),
 .out1(out1_tb),
 .out2(out2_tb),
 .out3(out3_tb));
 
 
 parameter clock_period=10; 
 
 
 initial
 begin
 
 A_tb='b0;
 B_tb='b0;
 
 #3
 if( out1_tb==7'b1000000 & out2_tb==7'b1000000 & out3_tb==7'b1000000)
 $display ("test passed");
 else
   begin
    $display ("test failed the expected is 'b1000000 and the truth of out1 is %b at time =%0t",out1_tb,$time);
    $display ("test failed the expected is 'b1000000 and the truth of out2 is %b at time =%0t",out2_tb,$time);
    $display ("test failed the expected is 'b1000000 and the truth of out3 is %b at time =%0t ",out3_tb,$time);
   end
 #(clock_period)
 
 A_tb='d3;
 B_tb='d4;
 #3
 if( out1_tb==7'b0100100 & out2_tb==7'b1111001 & out3_tb==7'b1000000)
   $display ("test passed");
 else
   begin
    $display ("test failed the expected is 'b0100100 and the truth of out1 is %b at time =%0t ",out1_tb,$time);
    $display ("test failed the expected is 'b1111001 and the truth of out2 is %b at time =%0t ",out2_tb,$time);
    $display ("test failed the expected is 'b1000000 and the truth of out3 is %b at time =%0t ",out3_tb,$time);
  end
 #(clock_period)
 
 A_tb='d11;
 B_tb='d11;
 #3
 if( out1_tb==7'b1111001 & out2_tb==7'b0100100   & out3_tb==7'b1111001)
    $display ("test passed");
 else
   begin
    $display ("test failed the expected is 'b0100100 and the truth of out1 is %b at time =%0t ",out1_tb,$time);
    $display ("test failed the expected is 'b1111001 and the truth of out2 is %b at time =%0t ",out2_tb,$time);
    $display ("test failed the expected is 'b0100100 and the truth of out3 is %b at time =%0t ",out3_tb,$time);
  end


end
endmodule


