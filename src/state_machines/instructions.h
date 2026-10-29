AdvanceAngle instrucciones(float Mag_Advance, float max_angle){

 AdvanceAngle gen_vector;

 static int step=0;

 step++;

 gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
 //gen_vector=generate_output(LEFT,Mag_Advance,max_angle);

//  gen_vector=generate_output(FORWARD,Mag_Advance,max_angle);
//  gen_vector=generate_output(STOP,Mag_Advance,max_angle);
//  gen_vector=generate_output(RIGHTADVANCE,Mag_Advance,max_angle);
//  gen_vector=generate_output(RIGHTADVANCETWICE,Mag_Advance,max_angle);
//   gen_vector=generate_output(LEFTADVANCE,Mag_Advance,max_angle);
//  gen_vector=generate_output(LEFTADVANCETWICE,Mag_Advance,max_angle);
// printf("TURN LEFT\n");

 return gen_vector;

}


