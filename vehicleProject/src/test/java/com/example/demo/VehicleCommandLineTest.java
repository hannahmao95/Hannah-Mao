package com.example.demo;

import static org.junit.jupiter.api.Assertions.*;

import java.util.Date;

import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@SpringBootTest
class VehicleCommandLineTest {
	
	
	@Test
	public void VehicleCommandLineRunnertest() {
		Vehicle vehicle = new Vehicle();
		vehicle.setId(123l);
		vehicle.setVehicleType("honda");
		vehicle.setUtilDate(new Date());
		
	}

}
