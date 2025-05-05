void driveconditions() {
  
  if (Ly > 30)  //fwd
  {
    z = mapping(Ly);
    run_motor(7, z);
  } else if (Ly < -30)  //back
  {
    z = mapping(Ly);
    run_motor(8, z);
  } else if (Lx < -30)  //left
  {
    z = mapping(Lx);
    run_motor(1, z);
  } else if (Lx > 30)  //right
  {
    z = mapping(Lx);
    run_motor(2, z);
  } else if (Rx > 30)  //clockwise
  {
    z = mapping(Rx);
    run_motor(3, z);
  } else if (Rx < -30)  //anticlockwise
  {
    z = mapping(Rx);
    run_motor(4, z);
  } else if (z > 0)  //stop1 (starts stoping gradually)
  {
    z = -10;
    run_motor(6, z);
    delay(100);
  } else  //finally stops (stop2)
  {
    z = 0;
    run_motor(7, z);
  }
}