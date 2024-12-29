module Shift_Add3 (
    input [7:0] binary,  // 8-bit binary input
    output reg [11:0] bcd  // 12-bit BCD output (to handle 8-bit binary to 3-digit BCD conversion)
);

reg [19:0] temp;  // Temporary register to hold intermediate results
integer i;

always @(*) begin
    // Initialize temporary register and BCD output
    temp = {12'b0,binary};

    // Load binary input into the BCD result
    for (i = 0; i < 8; i = i + 1) begin
        // Shift everything left before adding the next bit
        

        // Check each BCD digit and add 3 if necessary
        if (temp[11:8] >= 5)
            temp[11:8] = temp[11:8] + 3;
       else
        temp[11:8] = temp[11:8];
        
        if (temp[15:12] >= 5)
            temp[15:12] = temp[15:12] + 3;
       else
         temp[15:12] = temp[15:12];
         
        if (temp[19:16] >= 5)
            temp[19:16] = temp[19:16] + 3;
       else
        temp[19:16] = temp[19:16] ;
        
        
        
        temp = temp << 1;
        
            
        

        
    end

    // Decode output from temp
    bcd = temp[19:8];
end

endmodule
