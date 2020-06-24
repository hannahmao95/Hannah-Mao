package com.example.demo;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.PrePersist;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

@Entity
@Table(name="Vehicle")
class Vehicle{
	
	@Id 
	@GeneratedValue(strategy=GenerationType.IDENTITY) 
	private long id;
  
	@Column(name = "vehicle_type", nullable = false)
	private String vehicleType;
	
	@Column(name = "date")
	@Temporal(TemporalType.DATE)
	private Date date;
	



	public Vehicle(String vehicleType) {
		super();
		// TODO Auto-generated constructor stub
		this.vehicleType= vehicleType;
	}

	public Vehicle() {
		
	}
	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public String getVehicleType() {
		return vehicleType;
	}

	public void setVehicleType(String vehicleType) {
		this.vehicleType = vehicleType;
	}
	
	public Date getUtilDate() {
		return date;
	}

	public void setUtilDate(Date date) {
		this.date = date;
	}
	
	@Override
	public String toString() {
		return "Vehicle [id=" + id + ", vehicleType=" + vehicleType + ", Date=" + date + "]";
	}
	
	
	
}
