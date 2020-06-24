package com.example.demo;

import java.util.Collection;
import java.util.Date;
import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.format.annotation.DateTimeFormat;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
class VehicleRestController {
	@Autowired
	VehicleRepository vehicleRepository;

	@GetMapping("/vehicles")
	List<Vehicle> findallvehicles() {
		return this.vehicleRepository.findAll();
	}

	@GetMapping("/vehicles/id/{id}")
	@ResponseBody
	public Optional<Vehicle> findvehicleById(@PathVariable Long id) {
		System.out.println(id);
		return this.vehicleRepository.findById(id);
	}

	@GetMapping("/vehicles/type/{vehicleType}")
	@ResponseBody
	public Collection<Vehicle> findvehicleByName(@PathVariable String vehicleType) {

		return this.vehicleRepository.findByVehicleType(vehicleType);

	}

	@PostMapping("/vehicles/{vehicleType}")
	@ResponseBody
	public void savevehicle(@PathVariable String vehicleType) {

		this.vehicleRepository.saveVehicle(vehicleType);
	}

}