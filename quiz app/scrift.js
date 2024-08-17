const questions = [
    {
        question :"which is the largest animals in the world ?",
        answers:[
            {text:"shark",correct:false},
            {text:"blue whale",correct:true},
            {text:"elephant",correct:false},
            {text:"dog",correct:false}
           ]
    },
    {
        question :"which is the smallest country in the world ?",
        answers:[
            {text:"vatican city",correct:true},
            {text:"pakistan",correct:false},
            {text:"india",correct:false},
            {text:"turkay",correct:false}
           ]
             
    },
    {
        question :"which is the smallest continent in the world ?",
        answers:[
            {text:"australia",correct:true},
            {text:"america",correct:false},
            {text:"asia",correct:false},
            {text:"none of them",correct:false}
           ]
             
    },
    {
        question :"who is the founder of pakistan ?",
        answers:[
            {text:"ali khan",correct:false},
            {text:"zahid jinnah",correct:false},
            {text:"muhammad ali jinnah",correct:true},
            {text:"jinnah khan",correct:false}
           ]
    }
];




const  questionelement = document.getElementById("question");
const  answerbtn = document.getElementById("answer-buttons");
const  nextbutton = document.getElementById("next-btn");



let currentquestion = 0;
let score = 0;





function startquiz(){
    currentquestion =0;
    score =0;
    nextbutton.innerHTML="Next";
    showquestion();

}






function showquestion(){

    resetstate();

    let currentq = questions[currentquestion];
    let questionNo = currentquestion + 1;
    questionelement.innerHTML = questionNo + "." + currentq.question;

    currentq.answers.forEach(answer=>{
        const button = document.createElement("button");
        button.innerHTML = answer.text;
        button.classList.add("btn");
        answerbtn.appendChild(button);

        if(answer.correct){
            button.dataset.correct = answer.correct;
        }
        button.addEventListener("click" , selectanswer)
    })
}




function resetstate(){
    nextbutton.style.display = "none";
    while(answerbtn.firstChild){
        answerbtn.removeChild(answerbtn.firstChild);
    }
}






function selectanswer(e){
    const selectbtn = e.target;
    const iscorrect = selectbtn.dataset.correct === "true";
    if(iscorrect){
        selectbtn.classList.add("correct");
        score++;
    }else{
        selectbtn.classList.add("incorrect");
    }
     Array.from(answerbtn.children).forEach(button=>{
        if(button.dataset.correct === "true"){
            button.classList.add("correct");
        }
        button.disabled = true;
     })
     nextbutton.style.display = "block";
}





function showscore(){
    resetstate();
    questionelement.innerHTML = `Your scored ${score} out of ${questions.length}`;
    nextbutton.innerHTML = "play Again";
    nextbutton.style.display = "block";
}





function handlenextbutton(){
    currentquestion++;
    if(currentquestion < questions.length){
        showquestion();
    }else{
        showscore();
    }
}

nextbutton.addEventListener("click" ,()=>{
    if(currentquestion < questions.length){
        handlenextbutton();
    }else{
        startquiz();
    }
})



startquiz();