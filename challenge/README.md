Shopping Data

This little program process a csv file.

There is a csv file that keeps a record of n order details for orders made at an online shopping website. The file has a .csv extension.

Each line contains a single record with the following column, in order:<br />
-Id of the order placed<br />
-Area where the order was delivered<br />
-Name of the product<br />
-Quantity of the product delivered in that order<br />
-Brand of the ordered product<br />

Example:<br />
ID944806,Willard Vista,Intelligent Copper,3,Hilll-Gorczany<br />
ID644525,Roger Centers,Intelligent Copper,1,Kuze-Bernhard<br />
ID348204,Roger Centers,Small Granite Shoes,4,Rowe and Legros<br />
ID710139,Roger Centers,Intelligent Copper,4,Hilll-Gorczany<br />
ID426632,Roger Centers,Intelligent Copper,4,Hilll-Gorczany<br />

Create two csv files named 0_input_file_name and 1_inputfile_name

0_input_file_name - In the first column , list the product Name. The second column should contain the average quantity of the product purchase per order.

1_input_file_name - In the first column, list the product Name. The second column should be most popular Brand for that product. Most popular is defined as he brand with the most total orders for the item, not the quantity purchased. 


Sample Explanation:<br />
ID944806,Willard Vista,Intelligent Copper,3,Hilll-Gorczany<br />
ID644525,Roger Centers,Intelligent Copper,1,Kuze-Bernhard<br />
ID348204,Roger Centers,Small Granite Shoes,4,Rowe and Legros<br />
ID710139,Roger Centers,Intelligent Copper,4,Hilll-Gorczany<br />
ID426632,Roger Centers,Intelligent Copper,4,Hilll-Gorczany<br />


File 
0_input_file_name is created based on:<br />
There are 4 orders for Intelligent Copper Knife products that total 12 items.<br />
There is 1 order for Small Granite Shoes totaling 4 items.<br />

There are 5 total orders, so the average per order is 12/5=2.4 for Intelligent Copper Knife, and 4/5=0.8 for Small Granite Shoes.

0_input_example.csv:<br />
Intelligent Copper,2.4<br />
Small Granite Shoes,0.8<br />


1_input_file_name is created based on:<br />
-There are 4 orders for Intelligent Copper Knife,<br />
3 Branded Hill-Gorczany and<br />
1 Branded Kunze-Bernhar<br />
-There is 1 order for Small Granite shoes made by Rowe and Legros.<br />

The most popular brand for Intelligent Copper Knife is Hill-Gorczany<br />
The most popular brand for Small Granite shoes is Rowe and Legros<br />

1_input_example.csv:<br />
Intelligent Copper	Hilll-Gorczany<br />
Small Granite Shoes	Rowe and Legros<br />








