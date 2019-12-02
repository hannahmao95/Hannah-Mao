import { Component, OnInit, OnDestroy} from '@angular/core';
import {Recipe} from '../recipe.model';
import { RecipeService } from '../recipe.service';
import { Router, ActivatedRoute } from '@angular/router';
import { Subscription } from 'rxjs';


@Component({
  selector: 'app-recipe-list',
  templateUrl: './recipe-list.component.html',
  styleUrls: ['./recipe-list.component.css']
})
export class RecipeListComponent implements OnInit, OnDestroy{

  recipes:Recipe[]=[
    new Recipe('A Test Recipe','This is simply a test','https://www.asweetpeachef.com/wp-content/uploads/2018/05/healthy-spring-roll-recipes-7.jpg',[]),
    new Recipe('Another Test Recipe','This is simply a test','https://www.asweetpeachef.com/wp-content/uploads/2018/05/healthy-spring-roll-recipes-7.jpg',[])
  ];

  subscription:Subscription;

  constructor(private recipeService:RecipeService,
              private router:Router,
              private route: ActivatedRoute) { }

  ngOnInit() {
    this.subscription=this.recipeService.recipesChanged
      .subscribe(
        (recipes:Recipe[])=>{
          this.recipes= recipes;
        }
      );

    this.recipes=this.recipeService.getRecipes();
  }
  onNewRecipe(){
    this.router.navigate(['new'],{relativeTo:this.route});
  }

  ngOnDestroy(){
    this.subscription.unsubscribe();
  }
}
