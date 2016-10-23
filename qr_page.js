
function addQR(id)
{
	var options = {
	  cellSize: (5,5),
	  data: id.href
	};
	options.logo={};
	options.logo.text="ViSG";
	options.logo.color="#2c74af";
	const canvas = qrgen.canvas(options);
	block=document.getElementById("qr_div");
	block.appendChild(canvas);
	show(block);
};
function rmQR(id)
{
	block=document.getElementById("qr_div");
	hide(block);
	block.removeChild(block.childNodes[0]);
};
function show(n)
{
	<!-- 将二维码显示在页面右下角 -->
	n.style.position="fixed";
	n.style.right="25px";
	n.style.bottom="25px";
	n.style.display="inline-block";
}
function hide(n)
{
	n.style.display="none";
}