module UNSIGNED_MULT  #(parameter width=4 )(
 input wire  [width-1:0] A,
 input wire  [width-1:0] B,
 output reg  [2*width-1:0] C
);
always@(*)
 begin 

	C=A*B;


 end
 endmodule