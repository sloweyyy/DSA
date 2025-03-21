/**
 * @param {string[]} recipes
 * @param {string[][]} ingredients
 * @param {string[]} supplies
 * @return {string[]}
 */
var findAllRecipes = function (recipes, ingredients, supplies) {
    const indegree = new Map(); // Tracks the number of unmet dependencies for each recipe
    const graph = new Map(); // Adjacency list for recipes and their dependencies
    const supplySet = new Set(supplies); // Set of available supplies for quick lookup

    // Initialize the graph and indegree map
    for (let i = 0; i < recipes.length; i++) {
        const recipe = recipes[i];
        const recipeIngredients = ingredients[i];
        indegree.set(recipe, 0); // Initialize indegree for each recipe
        for (const ingredient of recipeIngredients) {
            if (!graph.has(ingredient)) {
                graph.set(ingredient, []);
            }
            graph.get(ingredient).push(recipe); // Add recipe as dependent on this ingredient
            indegree.set(recipe, (indegree.get(recipe) || 0) + 1); // Increment indegree for the recipe
        }
    }

    const queue = []; // Queue for processing recipes
    for (const supply of supplies) {
        if (graph.has(supply)) {
            queue.push(supply); // Start with available supplies
        }
    }

    const result = [];
    while (queue.length > 0) {
        const current = queue.shift();
        if (recipes.includes(current)) {
            result.push(current); // Add recipe to result if it's a recipe
        }
        if (graph.has(current)) {
            for (const dependent of graph.get(current)) {
                indegree.set(dependent, indegree.get(dependent) - 1); // Reduce indegree
                if (indegree.get(dependent) === 0) {
                    queue.push(dependent); // Add to queue if all dependencies are met
                }
            }
        }
    }

    return result;
};
