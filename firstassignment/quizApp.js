var stackData = [];
var stackID= [];
var stackCID = [];
let arrayDrop = [];

function undo(){
    
	var getFromStackID = stackID.pop();
	var getFromStackData = stackData.pop();
	var getFromStackCID= stackCID.pop();
	
	console.log(getFromStackID);
	console.log(getFromStackData);
	console.log(getFromStackCID);

    //assigne the left column to the right column
	document.getElementById(getFromStackID).innerHTML= getFromStackData;
	
	//clear the right column, assign the right column back to drop
	document.getElementById(getFromStackCID).innerHTML= "drop";

	//allows the left column to be dragged
	document.getElementById(getFromStackID).setAttribute("draggable",true);
	
}

function init(){
var button = document.getElementById("Undo");
	button.addEventListener("click", pop, false);
}


function allowDrop(ev) { //hover
  ev.preventDefault();
}

function drag(ev) {
  ev.dataTransfer.setData("text", ev.target.id);
}

var dataElement;

function drop(ev) {

  ev.preventDefault();
  var dropbox = ev.target.innerHTML;

	if ( dropbox == "drop"){
	
 	var dataID = ev.dataTransfer.getData("text");
 	dataElement= document.getElementById(dataID);
       
 	stackID.push(dataID); //push the ID and element onto stack
 	stackData.push(dataElement.innerHTML);
 	stackCID.push(ev.target.id);                   
  
    //drop terms to dropboxes
	ev.target.innerHTML= dataElement.innerHTML;

	//set the links of dropboxes to that of drag boxes
	ev.target.setAttribute("droppedIDLink", dataElement.getAttribute("LinkID"));
	
  	//assigning the term box to be empty
  	dataElement.innerHTML= " ";
  	dataElement.setAttribute("draggable",false);

  }

}

//timer

function startTime(seconds){
            var h = Math.floor(seconds / 3600), 
                        m = Math.floor(seconds / 60) % 60, 
                        s = seconds % 60;
                    if (h < 10) h = "0" + h;
                    if (m < 10) m = "0" + m;
                    if (s < 10) s = "0" + s;
                    return h + ":" + m + ":" + s;
}

 			var count = 0;
 			var counter ;

function startTimer(){
                counter = setInterval(timer, 1000);
}

                
function timer() {
                    count++;
                    document.getElementById('timer').innerHTML = startTime(count);
}
            

function startbutton() {

		var val = event.target.getAttribute("nextstate");
		event.target.value = val;
		switch(val) {					
			case "End":
				val = "Play";
				startTimer();
				break;
						
				case "Play":
				val = "End";
				clearInterval(counter);

				drag1.setAttribute("draggable",false);
 			 	drag2.setAttribute("draggable",false);
 			 	drag3.setAttribute("draggable",false);
 				drag4.setAttribute("draggable",false);
 			 	drag5.setAttribute("draggable",false);
				break;
		}
				event.target.setAttribute("nextstate", val);

	    //assigning shuffled columns 

		for (var j= 0; j<5; j++){
			
			document.getElementById("drag"+(j+1)).innerHTML=arrayTerm[j].value;

			document.getElementById("drag"+(j+1)).setAttribute("LinkID", arrayTerm[j].id); 

			document.getElementById("defb"+(j+1)).innerHTML=arrayDef[j].value;
			
		}
}


    fetch('quizApp.json')
  	.then(function(response) {
     	return response.json();

  	})
	  
	.then(function(data) {
	  	appendJson(data);

	})
     
	.catch(function(err) {
     	console.log('error:' + err);

    });
 
   function shuffle(array){
   array.sort(()=>Math.random()-0.5);
   }
 	
   let arrayTerm = [];
   let arrayDef = [];
  
  //Appending the Json Data to HTML
  //randomize 

function appendJson(data){

         //shuffle the entire json file 
         shuffle (data);
         //var dragItem;

        //debugger;
		for (var i= 0; i<data.length; i++){
			
           	arrayTerm.push({

                id: data[i].id,
           		value: data[i].term

           	}); //push json data to array holding the terms
             arrayTerm.sort(function(a, b){return 0.5 - Math.random()}); //randomize Term Columns
       

			arrayDef.push({
			   id: data[i].id, 
			   value: data[i].definition
			}); //push json data to array holding the definition
          	arrayDef.sort(function(a, b){return 0.5 - Math.random()}); //randomize Def Columns


            if(i>3){
		    break;    
		    }  

		} 
}	
	

function showScore(){

		var count=0;
	
		for (var k= 0; k<5; k++) {
          
			 arrayDrop.push({

                 id:    document.getElementById("drop"+(k+1)).getAttribute("droppedIDLink"), //get the id of dropboxes
			 	value:  document.getElementById("drop"+(k+1)).innerHTML //get the innerHTML of dropboxes
		     });
			

			if(arrayDrop[k].id == arrayDef[k].id){

	 			//highlight dropbox green	
	 			document.getElementById("drop"+(k+1)).setAttribute("style","background-color:green");
	 			
	 			count++;
	 			
	 		}

	 		else{
	 			//highlight dropbox red
	 		   document.getElementById("drop"+(k+1)).setAttribute("style","background-color:red");
	 			
	 		}

		}

       
        
        var score=count;
        document.getElementById("myText").innerHTML = score;

	 	
}	

 	


