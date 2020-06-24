package com.example.demo;

import static org.junit.jupiter.api.Assertions.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

import org.junit.Before;
import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.mockito.InjectMocks;
import org.mockito.MockitoAnnotations;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;


@RunWith(SpringRunner.class)
@SpringBootTest
@WebMvcTest(controllers=VehicleRestController.class)
class VehicleRestControllerTest {
    @InjectMocks
    private VehicleRestController vehicleRestController;
   
	@Autowired                           
    private MockMvc mockMvc; 
	
	 @Before
	 public void setup() {
	        MockitoAnnotations.initMocks(this);
	        this.mockMvc = MockMvcBuilders.standaloneSetup(vehicleRestController).build();
	    }
	
	@Test
	public void testfindallvehicles() throws Exception {
		this.mockMvc.perform(get("/vehicles")).andExpect(status().isOk());
	}
	
	@Test
	public void testfindvehicleById() throws Exception {
		this.mockMvc.perform(get("/vehicles/id/{id}")).andExpect(status().isOk());
	}
	
	@Test
	public void testfindvehicleByName() throws Exception {
		this.mockMvc.perform(get("/vehicles/type/{vehicleType}")).andExpect(status().isOk());
	}
	

}
