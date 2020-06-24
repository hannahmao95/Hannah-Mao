package com.example.demo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

@Component
class VehicleCommandLineRunner implements CommandLineRunner{
	@Autowired 
	VehicleRepository vehicleRepository;
		
	@Override
	public void run(String...args)throws Exception{
		for(Vehicle v: this.vehicleRepository.findAll()) {
			System.out.println(v.toString());
		}
	}
	
}