<template>
  <footer>
    <div class="footer-content">
      <p>All rights reserved.</p>
      <nav>
        <ul>
          <li><a href="/">About</a></li>
          <li><a href="/">Contact</a></li>
        
        </ul>
      </nav>
    </div>
  </footer>
</template>

<script>
export default {
  name: 'Footer'
}
</script>

<style scoped>
.footer-content {
  text-align: center;
  padding: 1rem;
  background-color: #f8f9fa;
}
.footer-content nav ul {
  list-style-type: none;
  padding: 0;
}
.footer-content nav ul li {
  display: inline;
  margin: 0 10px;
}
</style>