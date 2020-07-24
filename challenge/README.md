Shopping Data

This little program process a csv file.

There is a csv file that keeps a record of n order details for orders made at an online shopping website. The file has a .csv extension.

Each line contains a single record with the following column, in order:
-Id of the order placed
-Area where the order was delivered
-Name of the product
-Quantity of the product delivered in that order
-Brand of the ordered product

Example:
ID944806,Willard Vista,Intelligent Copper,3,Hilll-Gorczany
ID644525,Roger Centers,Intelligent Copper,1,Kuze-Bernhard
ID348204,Roger Centers,Small Granite Shoes,4,Rowe and Legros
ID710139,Roger Centers,Intelligent Copper,4,Hilll-Gorczany
ID426632,Roger Centers,Intelligent Copper,4,Hilll-Gorczany

Create two csv files named 0_input_file_name and 1_inputfile_name

0_input_file_name - In the first column , list the product Name. The second column should contain the average quantity of the product purchase per order.

1_input_file_name - In the first column, list the product Name. The second column should be most popular Brand for that product. Most popular is defined as he brand with the most total orders for the item, not the quantity purchased. 


Sample Explanation:
ID944806,Willard Vista,Intelligent Copper,3,Hilll-Gorczany
ID644525,Roger Centers,Intelligent Copper,1,Kuze-Bernhard
ID348204,Roger Centers,Small Granite Shoes,4,Rowe and Legros
ID710139,Roger Centers,Intelligent Copper,4,Hilll-Gorczany
ID426632,Roger Centers,Intelligent Copper,4,Hilll-Gorczany


File 
0_input_file_name is created based on:
There are 4 orders for Intelligent Copper Knife products that total 12 items.
There is 1 order for Small Granite Shoes totaling 4 items.

There are 5 total orders, so the average per order is 12/5=2.4 for Intelligent Copper Knife, and 4/5=0.8 for Small Granite Shoes.

0_input_example.csv:
Intelligent Copper,2.4
Small Granite Shoes,0.8


1_input_file_name is created based on:
-There are 4 orders for Intelligent Copper Knife,
3 Branded Hill-Gorczany and
1 Branded Kunze-Bernhar
-There is 1 order for Small Granite shoes made by Rowe and Legros.

The most popular brand for Intelligent Copper Knife is Hill-Gorczany
The most popular brand for Small Granite shoes is Rowe and Legros

1_input_example.csv:
Intelligent Copper	Hilll-GorczanySmall Granite Shoes	Rowe and Legros








