
                                                        ###functions







alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
keywords = ["always", "and", "assign", "automatic", "begin", "bind", "bit", "buf", "bufif0", "bufif1", "byte", "case", "casex", "casez", "cell", "class", "cmos", "config", 
                "const", "constraint", "context", "continue", "cover", "covergroup", "coverpoint", "default", "defparam", "design", "disable", "dist", "do", "edge", "else", "end", 
                "endcase", "endclass", "endconfig", "endfunction", "endgenerate", "endmodule", "endgroup", "endprimitive", "endspecify", "endtable", "endtask", "enum", "event", 
                "expect", "export", "extends", "extern", "final", "first_match", "for", "force", "forever", "fork", "function", "generate", "genvar", "highz0", "highz1", "if", 
                "iff", "ifnone", "ignore_bins", "illegal_bins", "implements", "import", "include", "initial", "inout", "input", "inside", "instance", "int", "integer", "interconnect", 
                "interface", "join", "join_any", "join_none", "large", "let", "liblist", "library", "local", "localparam", "logic", "macromodule", "matches", "medium", "modport", 
                "module", "mux", "nand", "negedge", "nettype", "new", "nmos", "nor", "noshowcancelled", "not", "notif0", "notif1", "null", "or", "output", "package", "parameter", "pmos", 
                "posedge", "primitive", "priority", "program", "property", "protected", "pull0", "pull1", "pulldown", "pullup", "pulsestyle_ondetect", "pulsestyle_onevent", "rand", 
                "randcase", "randc", "randsequence", "real", "realtime", "ref", "reg", "release", "repeat", "return", "rnmos", "rpmos", "rtran", "rtranif0", "rtranif1", "scalared", 
                "sequence", "shortint", "shortreal", "showcancelled", "signed", "small", "solve", "specify", "specparam", "static", "string", "strong0", "strong1", "struct", 
                "super", "supply0", "supply1", "table", "tagged", "task", "this", "throughout", "time", "timeprecision", "timeunit", "tran", "tranif0", "tranif1", "tri", "tri0", 
                "tri1", "triand", "trior", "trireg", "type", "typedef", "union", "unique", "unsigned", "use", "var", "vectored", "virtual", "void", "wait", "wait_order", 
                "wand", "weak0", "weak1", "while", "wire", "with", "within", "wor", "xnor", "xor",""]

def keyword_checker():
    cond = False
    special_char = ["!", "@", "\n" ,"#", "$", "%", "^", "&", "*", "(", ")", "-", " ", "=", "+", "{", "}", "[", "]", "\\", "|", ";", ":", "'", "\"", ",", "<", ".", ">", "/", "?", "~", "`"]
    
    while (cond == False):
        temp_name = input("Enter string: ")
        if temp_name == "" or temp_name.isspace():
              print("Sorry, you enter enter key")
        elif temp_name[0] in alphabet:
            if temp_name in keywords:
                print("Sorry, you entered a keyword.")
                cond = False
            else:
                has_special_char = False
                for char in temp_name:
                    if char in special_char:
                        has_special_char = True
                        break
                if has_special_char:
                    print("Sorry, you entered a string with a special character.")
                    cond = False
                else:
                    cond=if_exist(temp_name)
                    if(cond==True):
                        print("Name accepted.")
                        return temp_name
                    

        else:
            print("Sorry, you entered a non-string.")


           

def integer_checker():
    cond =False
    while (cond == False)  :
         try:
              temp_number=int(input("please enter positive integer number  "))
              if (type(temp_number) == type(5)) and (temp_number>=0):
                
                      cond=True
                      return temp_number
         except:
              print("sorry you input non integer number")

def YesNo_checker():

  
    cond = False
    while (cond== False):
         temp_type=input(" please enter 'y'for yes or 'n' no   ")
         if temp_type in alphabet:
                 if(temp_type=="y")or (temp_type=="Y") or (temp_type=="n") or (temp_type=="N") :
                        cond=True
                        return temp_type
         else:
          print("wrong char")
          cond=False


all_names=[]
def if_exist(arg):
        while True:
            if arg in all_names:
                print("this name exist ,please enter another name")
                return False
            else:
                all_names.append(arg)
                return True
                break

def lowercase_string(arg):
        if arg in keywords:
            print(f"warning! the name is mostly like a reserved keyword,   {arg}")
            



  ####                                            main                    ************************************************************

  ############                              name of module         =================
    
print("enter your module name")
Module_name=keyword_checker()                          ###check if the first char is alphabet and saved in keyword or not and have special char or not && check if the name are existed or not
lowercase_string(Module_name.lower())                                  
f=open(f"{Module_name.upper()}.v","w")                 ### write the module name in upper char
f.write(f"module {Module_name.upper()}")
f.close()
f1=open(f"{Module_name.upper()}_tb.v","w")
f1.write(f"module {Module_name.upper()}_tb")
f1.close()





#############                               parameters     ===============================================================================


                                   ###there a corner case in multi parameter ( ; )


print("enter number of parameters in your module ")
parameter_number=integer_checker()            ###check number if non neg
parameter_name=[]
parameter_value=[]
if(parameter_number!=0):
    f=open(f"{Module_name.upper()}.v","a")
    f.write("  #(parameter ")
    f1=open(f"{Module_name.upper()}_tb.v","a")
    f1.write("(); parameter ")
    for i in range(parameter_number):
       print("enter name of parameters in your module ")
       parameter_name.append(keyword_checker())
       lowercase_string(parameter_name[i].lower())
       print("enter the value of this parameter")
       parameter_value.append(integer_checker())
       f=open(f"{Module_name.upper()}.v","a")
       f1=open(f"{Module_name.upper()}_tb.v","a")
       f.write(f"{parameter_name[i]}={parameter_value[i]} ")
       f1.write(f"{parameter_name[i]}={parameter_value[i]} ")
       f.close()
       f1.close()

if parameter_number==0:
        f=open(f"{Module_name.upper()}.v","a")
        f.write(f"(\n")
        f.close()
        f1=open(f"{Module_name.upper()}_tb.v","a")
        f1.write(f"; \n")
        f1.close()
else:
        f=open(f"{Module_name.upper()}.v","a")
        f1=open(f"{Module_name.upper()}_tb.v","a")
        f.write(f")(\n")
        f1.write(f"; \n")
        f.close()
        f1.close()







#########                                        inputs            =============================================================


cond = False
while (cond== False):
    print("enter number of inputs")
    inputs_num=integer_checker()              ###check number if non neg
    if(inputs_num==0):
        print("you can't enter 0,at least you need 1 input")
    else:
        cond=True


inputs_name=[]
for i in range(inputs_num):
     print("enter input",i+1)
     input_name = keyword_checker()      ###check if the first char is alphabet and saved in keyword or not and have special char or not && check name are exist before or not
     lowercase_string(input_name.lower())     
     inputs_name.append(input_name.capitalize())         ###put the input name with first letter capital
     if(parameter_number!=0):
        print("are this  input paramterized")
        parametrized=YesNo_checker()                      ###check your input parametrized
        if(parametrized=="y")or (parametrized=="Y"):
               print("\n BE CAREFULL ,YOU MUST CHOOSE A PARAMETER \n")
               for m in range(parameter_number):
                       print("are this the parameter you want",parameter_name[m])
                       parametrized=YesNo_checker()
                       if(parametrized=="y")or (parametrized=="Y"):
                            f=open(f"{Module_name.upper()}.v","a")
                            f.write(f" input wire  [{parameter_name[m]}-1:0] {inputs_name[i]},\n")
                            f.close()
                            f1=open(f"{Module_name.upper()}_tb.v","a")
                            f1.write(f"  reg  [{parameter_name[m]}-1:0] {inputs_name[i]}_tb;\n")
                            f1.close()
                            break
                       else:
                           continue
        else:
              print("enter the width you want ")
              width=integer_checker()
              if(width==1):
                    f=open(f"{Module_name.upper()}.v","a")
                    f.write(f" input wire {inputs_name[i]},\n")
                    f.close()
                    f1=open(f"{Module_name.upper()}_tb.v","a")
                    f1.write(f" reg {inputs_name[i]}_tb;\n")
                    f1.close()
              else:
                  f=open(f"{Module_name.upper()}.v","a")
                  f.write(f" input wire [{width-1}:0] {inputs_name[i]},\n")
                  f.close()
                  f1=open(f"{Module_name.upper()}_tb.v","a")
                  f1.write(f" reg [{width-1}:0] {inputs_name[i]}_tb;\n")
                  f1.close()
     else:
         print("enter the width you want ")
         width=integer_checker()
         if(width==1):
              f=open(f"{Module_name.upper()}.v","a")
              f.write(f" input wire {inputs_name[i]},\n")
              f.close()
              f1=open(f"{Module_name.upper()}_tb.v","a")
              f1.write(f" reg {inputs_name[i]}_tb;\n")
              f1.close()
         else:
              f=open(f"{Module_name.upper()}.v","a")
              f.write(f" input wire [{width-1}:0] {inputs_name[i]},\n")
              f.close()
              f1=open(f"{Module_name.upper()}_tb.v","a")
              f1.write(f" reg [{width-1}:0] {inputs_name[i]}_tb;\n")
              f1.close()





  ##################################      check system seq or not      =====================================================

print("are your system sequential ")
system_type=YesNo_checker()
if(system_type=="y")or (system_type=="Y"):
          f=open(f"{Module_name.upper()}.v","a")
          f.write(f" input wire CLK,\n")
          f.write(f" input wire RST,\n")
          f.close()
          f1=open(f"{Module_name.upper()}_tb.v","a")
          f1.write(f" reg CLK_tb ;\n")
          f1.write(f" reg RST_tb ;\n")
          f1.close()





##################                   outputs         ================================================================

cond = False
while (cond== False):
    print("enter number of outputs")
    outputs_num=integer_checker()
    if(outputs_num==0):
        print("you can't enter 0,at least you need 1 output")
    else:
        cond=True
        
outputs_name=[]
for i in range(outputs_num):
     print("enter output",i+1)
     output_name = keyword_checker()
     lowercase_string(output_name.lower())
     outputs_name.append(output_name.capitalize())
     if(parameter_number!=0):
         print("are this  output paramterized")
         parametrized=YesNo_checker()
         if(parametrized=="y")or (parametrized=="Y"):
            print("\n BE CAREFULL ,YOU MUST CHOOSE A PARAMETER \n")
            for m in range(parameter_number):
                   print("are this the parameter you want",parameter_name[m])
                   parametrized=YesNo_checker()
                   if(parametrized=="y")or (parametrized=="Y"):
                            f=open(f"{Module_name.upper()}.v","a")
                            f.write(f" output reg  [{parameter_name[m]}-1:0] {outputs_name[i]},\n")
                            f.close()
                            f1=open(f"{Module_name.upper()}_tb.v","a")
                            f1.write(f"  wire  [{parameter_name[m]}-1:0] {outputs_name[i]}_tb;\n")
                            f1.close()
                            break
                   else:
                           continue
         else:
             print("enter the width you want ")
             width=integer_checker()
             if(width==1):
                 f=open(f"{Module_name.upper()}.v","a")
                 f.write(f" output reg {outputs_name[i]},\n")
                 f.close()
                 f1=open(f"{Module_name.upper()}_tb.v","a")
                 f1.write(f" wire {outputs_name[i]}_tb;\n")
                 f1.close()
             else:
                 f=open(f"{Module_name.upper()}.v","a")
                 f.write(f" output reg [{width-1}:0] {outputs_name[i]},\n")
                 f.close()
                 f1=open(f"{Module_name.upper()}_tb.v","a")
                 f1.write(f" wire [{width-1}:0] {outputs_name[i]}_tb;\n")
                 f1.close()



f=open(f"{Module_name.upper()}.v","a")
f.write(f");\n")
f.close()


 



     ########                               dut in testbench   ========================================================


f1=open(f"{Module_name.upper()}_tb.v","a")
f1.write(f"\n\n\n\n\n\n{Module_name.upper()} DUT(\n")
f1.close()
if(system_type=="y")or (system_type=="Y"):
    f1=open(f"{Module_name.upper()}_tb.v","a")
    f1.write(f".CLK(CLK_tb),\n.RST(RST_tb),")
    f1.close()
for i in range(inputs_num):
    f1=open(f"{Module_name.upper()}_tb.v","a")
    f1.write(f"\n.{inputs_name[i]}({inputs_name[i]}_tb),")
    f1.close()
for i in range(outputs_num):
    f1=open(f"{Module_name.upper()}_tb.v","a")
    f1.write(f"\n.{outputs_name[i]}({outputs_name[i]}_tb),")
    f1.close()

print("enter the clock period")
clock_period=integer_checker()
f1=open(f"{Module_name.upper()}_tb.v","a")
f1.write(f");\n\n\n\n\n parameter clock_period={clock_period}; \n always #(clock_period/2) CLK_tb=!CLK_tb;")
f1.close()


########                                initial   =========================================================================


f1=open(f"{Module_name.upper()}_tb.v","a")
f1.write(f"\n\n\n\n\n\n\n initial \n begin \n")
f1.close()
if(system_type=="y")or (system_type=="Y"):
    f1=open(f"{Module_name.upper()}_tb.v","a")
    f1.write(f"CLK_tb='b0;\nRST_tb='b1")
    f1.close()
for i in range(inputs_num):
    f1=open(f"{Module_name.upper()}_tb.v","a")
    f1.write(f"\n{inputs_name[i]}_tb='b0")
    f1.close()
f1=open(f"{Module_name.upper()}_tb.v","a")
f1.write(f"\n #(clock_period) \n\n\n\n end \n endmodule")
f1.close()





     ##########################                       always block     ===================================================



if(system_type=="y")or (system_type=="Y"):                              ###sequential system
    print("are you posedge clk")
    clk_edge=YesNo_checker()
    if(clk_edge=="y")or (clk_edge=="Y"):
           f=open(f"{Module_name.upper()}.v","a")
           f.write(f"always@(posedge CLK")
           f.close()
    else:
         f=open(f"{Module_name.upper()}.v","a")
         f.write(f"always@(negedge CLK")
         f.close()

    print("are your RST asynchronus")               ###### asynchronous reset
    Synchronization=YesNo_checker()
    if(Synchronization=="y")or (Synchronization=="Y"):
             print("are you negedge RST")
             rst_edge=YesNo_checker()
             if(rst_edge=="y")or (rst_edge=="Y"):
                    f=open(f"{Module_name.upper()}.v","a")
                    f.write(f" or negedge RST)\n begin \n if(!RST) \n begin \n\n\n\n end \n else \n begin \n\n\n\n end \n end \n endmodule")
                    f.close()
             else:
                    f=open(f"{Module_name.upper()}.v","a")
                    f.write(f" or posgedge RST)\n begin \n if(RST)\n begin \n\n\n\n end \n else \n begin \n\n\n\n end \n end \n endmodule")
                    f.close()

    else:
           f=open(f"{Module_name.upper()}.v","a")
           f.write(f")\n begin \n if(!RST)\n begin \n\n\n\n end \n else \n begin \n\n\n\n end \n end \n endmodule")
           f.close()


else:                                               ######### combinational
    f=open(f"{Module_name.upper()}.v","a")
    f.write(f"always@(*)\n begin \n\n\n\n\n end\n endmodule")
    f.close()