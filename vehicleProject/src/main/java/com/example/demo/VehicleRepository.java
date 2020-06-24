package com.example.demo;

import java.util.Collection;
import java.util.Date;

import javax.transaction.Transactional;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

interface VehicleRepository extends JpaRepository<Vehicle,Long>{
	@Query(value="SELECT * FROM Vehicle v where v.vehicle_type=:type",nativeQuery = true)
	Collection<Vehicle> findByVehicleType(@Param("type")String type);
	
	@Modifying
	@Transactional
	@Query(value="Insert into Vehicle(vehicle_type)values(:type)",nativeQuery = true)
	void saveVehicle(@Param("type")String type);
}