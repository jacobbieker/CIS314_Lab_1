.data
  my_array  .word 3, 4573, 531, 35, 6, 6354, 3, 81  #Array
  array_size  .word   8
  largest .word 0

lw $t0, #Array
lw $t1, #Array_Size
lw $t2, #Largest

loopy: bgt $t0, $zero, then
          # Else block
          j end
          then:
            mult $t3, 4, $t1 #Get the current array spot
            bgt $t2, $t3
              sw $t2, $t3
            sub $t1, 1 # Decrement the counter
            mult $t0, 4 # Add offset for array, to continue loop
            j loopy
       end:
          #Return 0 or equiv
