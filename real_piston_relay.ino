void relay()   //gripper
{
  
    // L1 Button Controls Relay 1 jaw open
    if (ps5.Up()) 
    {
      digitalWrite(RELAY_1_PIN, HIGH);
    } else 
    {
      digitalWrite(RELAY_1_PIN, LOW);
    }

    // L2 Button Controls Relay 2
    if (ps5.Down()) 
    {
      digitalWrite(RELAY_2_PIN, HIGH);
    } else 
    {
      digitalWrite(RELAY_2_PIN, LOW);
    }
  
}
  