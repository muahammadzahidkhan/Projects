
console.log("lets write javascrift")
// let songs;

const songscollection = {
  card1: [
    "file:///E:/sem%20web/Project/song/1.mp3",
    "file:///E:/sem%20web/Project/song/2.mp3",
    "file:///E:/sem%20web/Project/song/3.mp3"
  ],

  card2: [
    "file:///E:/sem%20web/Project/song/4.mp3",
    "file:///E:/sem%20web/Project/song/5.mp3",
    "file:///E:/sem%20web/Project/song/6.mp3",
    "file:///E:/sem%20web/Project/song/7.mp3"
   ],

  card3: [
    "file:///E:/sem%20web/Project/song/8.mp3",
    "file:///E:/sem%20web/Project/song/9.mp3",
    "file:///E:/sem%20web/Project/song/10.mp3",
    "file:///E:/sem%20web/Project/song/11.mp3"
  ]
};





function secondtominutesecond(time) {
  const minutes = Math.floor(time / 60);
  const seconds = Math.floor(time % 60);
  return `${minutes}:${seconds < 10 ? '0' : ''}${seconds}`;
}


let currentsong = new Audio();

const playmusic = (e, pause = false ) => {
  currentsong.src = "E:/sem web/Project/song/" + e;

  if (!pause) {
    currentsong.play();
    play.src = "Assists/pause.svg";
  }


  document.querySelector(".songinfo").innerHTML = e;
  document.querySelector(".songtime").innerHTML = "00:00 / 00:00";
}
function main() {
  let songs;
  // adding eventlistner on each song 
  const addSongListeners = () => {
    playmusic(`${songs[0].replace("file:///E:/sem%20web/Project/song/", "")}`, true);
    Array.from(document.querySelector(".songlist").getElementsByTagName("li")).forEach(li => {
      li.addEventListener("click", () => {
        playmusic(li.querySelector(".info").firstElementChild.innerHTML);
      });
    });
  };


  //adding eventlistner play buttons
  play.addEventListener("click", () => {
    if (currentsong.paused) {
      play.src = "Assists/pause.svg";
      currentsong.play()

    } else {
      currentsong.pause()
      play.src = "Assists/play2.svg";
    }
  })

  // adding eventlistner on previous and next buttons
  previous.addEventListener("click", () => {
    let index = songs.indexOf(currentsong.src)
    if ((index - 1) >= 0) {
      playmusic(songs[index - 1].split("/").slice(-1)[0])
    }
  })

  next.addEventListener("click", () => {
    let index = songs.indexOf(currentsong.src)
    if ((index + 1) < songs.length) {
      playmusic(songs[index + 1].split("/").slice(-1)[0])
    }
  })

  //  adding listner for timeupdate
  currentsong.addEventListener("timeupdate", () => {
    console.log(currentsong.currentTime, currentsong.duration);
    document.querySelector(".songtime").innerHTML =
      `${secondtominutesecond(currentsong.currentTime)} / ${secondtominutesecond(currentsong.duration)}`;
    document.querySelector(".circle").style.left = (currentsong.currentTime / currentsong.duration) * 100 + '%';
  });

  // adding listner to seekbar

  document.querySelector(".seekbar").addEventListener("click", e => {
    let parcent = (e.offsetX / e.target.getBoundingClientRect().width) * 100
    document.querySelector(".circle").style.left = parcent + "%";
    currentsong.currentTime = ((currentsong.duration) * parcent) / 100;

  })
  // adding EventListener to humberger
  document.querySelector(".humberger").addEventListener("click", () => {
    document.querySelector(".left").style.left = "0";
  })
  // adding EventListener to close button
  document.querySelector(".close").addEventListener("click", () => {
    document.querySelector(".left").style.left = "-120%";
  })
  // add event to volume
  document.querySelector(".range").getElementsByTagName("input")[0].addEventListener("change", (e) => {
    // console.log(e.target.value,"/100")
    currentsong.volume = parseInt(e.target.value)/ 100
    // console.log(currentsong.volume,"uygftr")
    
  })

  // add event to cards
  Array.from(document.getElementsByClassName("card")).forEach((card,index)=> {
    // console.log(e)
    card.addEventListener("click", ((i) => {
      let songul = document.querySelector(".songlist ul")
      songul.innerHTML = "";
      songs = songscollection[`card${index+ 1}`];
      console.log(songs)
      for (const song of songs) {
        songul.innerHTML = songul.innerHTML + `<li>
                  <img class="invert" src="Assists/music.svg" alt="">
                  <div class="info ">
                    <div>${song.replace("file:///E:/sem%20web/Project/song/", "")}</div>
                    <div>Song Artist</div>
                  </div> 
                  <div class="playnow">
                  <span>PlayNow</span> 
                  <img class="invert" src="Assists/play2.svg" alt="">
                </div>  
                </li>` ;

      }
      addSongListeners();
    }))
  })



}

main();