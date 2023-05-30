big = document.querySelector('#user-locations')
childrens = Array.from(big.children) 
while(childrens.length > 31)
{
  childrens.shift();
}
i = 0;
hrs = 0;
min = 0;
while (i < childrens.length)
{
    if (childrens[i].tagName != 'g')
        childrens.splice(i, 1);
    i++;
}
i = 0;
while (i < childrens.length)
{
    let hrs_cell = childrens[i].getAttribute('data-original-title');
    if (hrs_cell != "0h00")
    {
        hrs += parseInt(hrs_cell.split('h')[0]);
        min += parseInt(hrs_cell.split('h')[1]);
    }
    i++;
}
if (min > 59)
{
    hrs += Math.floor(min / 60);
    min = min % 60;
}
if (hrs < 10){hrs = `0${hrs}`}
if (min < 10){min = `0${min}`}
res = `The last 30 days: ${hrs}h${min}`;
console.log(res);
div = document.createElement('div');
div.innerHTML = res;
div.style = "display: flex; width: 250px; height: 30px; position: fixed; bottom: 0px; right: 0%; z-index: 9999; background: rgba(0, 0, 0, 0) linear-gradient(45deg, rgb(41, 45, 57) 50%, rgb(85, 85, 85) 50%) repeat scroll 0% 0%; justify-content: center; align-items: center; transform: translate(0%); color: white; font-weight: bold;"
document.querySelector('body').append(div);
