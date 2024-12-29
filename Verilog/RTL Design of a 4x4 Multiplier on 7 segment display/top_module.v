module top_module #(parameter width=4) (
input wire [width-1:0] A,
input wire [width-1:0] B,
output wire [6:0] out1,
output wire [6:0] out2,
output wire [6:0] out3);

wire [2*width-1:0] mult_out;
wire [11:0] out_shift;






UNSIGNED_MULT U1 (
.A(A),
.B(B),
.C(mult_out));


shift_add3 A1 (
.binary(mult_out),
.bcd(out_shift));



seven_segment_decoder D1 (
.binary_input(out_shift[3:0]),
.segment_output(out1));


seven_segment_decoder D2 (
.binary_input(out_shift[7:4]),
.segment_output(out2));

seven_segment_decoder D3 (
.binary_input(out_shift[11:8]),
.segment_output(out3));


endmodule


