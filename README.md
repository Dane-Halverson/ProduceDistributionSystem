# Produce Distribution System

>Authors:
>Dane Halverson
>Marshall Bluhm
>Teddy Jeddeloh
>Timothy Okoroafor

This a program that takes in two json files( one for produce and one for schools ) and opens a gui to distribute them. The json files must be named `produce.json` and `schools.json` and must be in the same folder as the executable.



## Example of produce.json

	{
	    "date" : "Sept 18 2021",

	    "daysSincePicked" : 1,

	    "produce" : [
	    {
	        "type" : "tomatoes",
	        "weight" : 28,
	        "costPerPound" : 1.91,
	        "farm" : "Food Farm"
	    },
	    {
	        "type" : "apples",
	        "weight" : 12,
	        "costPerPound" : 0.80,
	        "farm" : "Little Small Farm",
	        "dateofpick" : "sep 17 2021"
	    },
	    {
	        "type" : "carrots",
	        "weight" : 45,
	        "costPerPound" : 0.50,
	        "farm" : "Food Farm"
	    }
	    ]
	}

## Example of schools.json

	{

	"schools":  [

		{

			"type":  "middle",

			"name":  "Ordean East Middle School",

			"budget":  320.00

		},

		{

			"type":  "middle",

			"name":  "Lincoln Park Middle School",

			"budget":  320.00

		},

		{

			"type":  "hs",

			"name":  "Denfeld High School",

			"budget":  820.00

		},

		{

			"type":  "ms",

			"name":  "Denfeld Middle School",

			"budget":  820.00

		},

		{

			"type":  "elem",

			"name":  "Myers Wilkins Elementary School",

			"budget":  320.00

		}

	]

	}
