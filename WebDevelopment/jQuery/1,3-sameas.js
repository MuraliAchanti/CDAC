$(document).ready(function(){
$('input[type="checkbox"').click(function(){
    if($('input[type="checkbox"]').prop('checked')==true)
    {
        var newform = $("#form1").clone();
        newform.filter('form').prop('id','form2');
        $('#form2').replaceWith(newform);
        $('#form2 select:first').val($('#form1 select:first').val());
        $('#form2 select:last').val($('#form1 select:last').val());
    }
});
$('#form1').keyup(function(){
    if($('input[type="checkbox"]').prop('checked')==true)
    {
        var newform = $("#form1").clone();
        newform.filter('form').prop('id','form2');
        $('#form2').replaceWith(newform);
        $('#form2 select:first').val($('#form1 select:first').val());
        $('#form2 select:last').val($('#form1 select:last').val());
    }
});
$('#form1 select:first').change(function()
{
    if($('input[type="checkbox"]').prop('checked')==true)
    {
        $('#form2 select:first').val($('#form1 select:first').val());
    }
});
$('#form1 select:last').change(function()
{
    if($('input[type="checkbox"]').prop('checked')==true)
    {
        $('#form2 select:last').val($('#form1 select:last').val());
    }
});
$('input[type="button"]').click(function(){
    if ( $('.form-inner-container:last').css('visibility') == 'hidden')
    {
    $('.form-inner-container:last').css('visibility','visible');
    $('input[type="button"]').prop('value','Hide');
    }
  else
    {
    console.log("arsenal");
    $('.form-inner-container:last').css('visibility','hidden');
    $('input[type="button"]').prop('value','Show');
    }
});
});