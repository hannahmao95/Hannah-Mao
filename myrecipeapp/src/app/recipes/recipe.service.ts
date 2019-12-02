
import {  Injectable } from '@angular/core';
import { Recipe } from './recipe.model';
import { Ingredient } from '../shared/ingredient.model';
import { ShoppingListService } from '../shopping-list/shopping-list.service';
import { Subject } from 'rxjs/internal/Subject';


@Injectable()
export class RecipeService{
    recipesChanged = new Subject<Recipe[]>();

    private recipes:Recipe[]=[
        new Recipe('A Test Recipe','This is simply a test','https://www.asweetpeachef.com/wp-content/uploads/2018/05/healthy-spring-roll-recipes-7.jpg',
        [
            new Ingredient('meat',1),
            new Ingredient('shimp',10),
            new Ingredient ('bacon',4)
          
        ]),
        new Recipe('Another Test Recipe','This is simply a test','https://www.asweetpeachef.com/wp-content/uploads/2018/05/healthy-spring-roll-recipes-7.jpg',
        [
            new Ingredient('mushroom',2),
            new Ingredient('lettus',10)
        ])
      ];

    constructor(private slService:ShoppingListService){}

    getRecipes(){
        return this.recipes.slice();
    }

    getRecipe(index:number){
        return this.recipes.slice()[index];     
    }

    addIngredientsToShoppingList(ingredients:Ingredient[]){
        this.slService.addIngredients(ingredients);
    }   

    addRecipe(recipe:Recipe){
        this.recipes.push(recipe);
        this.recipesChanged.next(this.recipes.slice());
    }

    updateRecipe(index:number, newRecipe:Recipe){
        this.recipes[index]=newRecipe;
        this.recipesChanged.next(this.recipes.slice());
    }

    deleteRecipe(index:number){
        this.recipes.splice(index, 1);
        this.recipesChanged.next(this.recipes.slice());
    }
}

