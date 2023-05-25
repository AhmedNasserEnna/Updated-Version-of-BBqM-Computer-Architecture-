#P = $a0 , T = $a1
# Wtime = $t0  
# total = $s0 , Multicounts = $s1 , P+T-1=$t3 ,0<total =$t4
addi $a0,$0,7 #P = 7
addi $a1,$0,1  #T = 1
addi $s0,$0,0  #total = 0
addi $s1,$0,3 #Multicounts = 3
add $t3,$a0,$a1  #P+T
addi $t3,$t3,-1  #P+T-1
addi $t0,$0,0 #Wtime = 0
beq $a0,$0,done #if(P==0)
j else
else :
beq $s1,$0,while #while(Multicounts != 0)
add $s0,$s0,$t3  #total = total + (P + T - 1)
addi $s1,$s1,-1  #Multicounts--
j else
while :	
slt $t4,$0,$s0  #total>0
beq $t4,$0,if  #if (total >0)
sub $s0,$s0,$a1  #total=total-T
addi $t0,$t0,1   #Wtime++
j while 
if : 
slt $t5,$s0,$0 #total < 0
beq $t5,$0,done
addi $t0,$t0,-1   #Wtime-- 
done :
sw $t0,8($0)

